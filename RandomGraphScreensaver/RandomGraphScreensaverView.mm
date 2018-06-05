//
//  RandomGraphScreensaverView.m
//  RandomGraphScreensaver
//
//  Created by Christian J Howard on 6/3/18.
//  Copyright © 2018 C. Howard. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Quartz/Quartz.h>
#import <time.h>
#import <random>
#import "multibody_sim/multibody_sim.hpp"
#import "RandomGraphScreensaverView.h"

@implementation RandomGraphScreensaverView {
    custom::graph graph;
    sim::sim_traits sim_traits;
}

- (instancetype)initWithFrame:(NSRect)frame isPreview:(BOOL)isPreview
{
    self = [super initWithFrame:frame isPreview:isPreview];
    if (self) {
        
        // set the animation time interval
        [self setAnimationTimeInterval:1/30.0];
        
        // set the simulation traits
        self->sim_traits.time = 0.0;
        self->sim_traits.dt = 1/30.0;
        self->sim_traits.attractor_pos[0] = frame.size.width*0.5;
        self->sim_traits.attractor_pos[1] = frame.size.height*0.5;
        
        // generate random graph
        std::default_random_engine g(time(nullptr));
        std::uniform_int_distribution<int> U(20,40);
        custom::generateRandomGraph(frame.size.width,
                                    frame.size.height,
                                    U(g),
                                    self->graph);
    }
    
    return self;
}

- (void)startAnimation
{
    [super startAnimation];
}

- (void)stopAnimation
{
    [super stopAnimation];
}

- (void)drawRect:(NSRect)rect
{
    [super drawRect:rect];
    [self drawScene];
}

- (void) drawGraph:(CGContextRef)ctx {
    
    // draw vertices
    auto& vertices = self->graph.getVertices();
    CGContextSetRGBFillColor (ctx, 0, 0, 0, 1);
    CGContextSetRGBStrokeColor(ctx, 0, 0, 0, 1);
    CGContextSetLineWidth(ctx, 1.0);
    
    for(int i = 0; i < vertices.size(); ++i){
        CGContextBeginPath(ctx);
        auto& vertex = vertices[i];
        auto& data = vertex.getData();
        CGContextAddArc(ctx, vertex[0], vertex[1], data.radius, 0, 2.0*M_PI, 1);
        CGContextFillPath(ctx);
        CGContextClosePath(ctx);
    }
    
    // draw the edges
    for(int i = 0; i < vertices.size(); ++i){
        int from_vertex = i;
        auto it = self->graph.getConnectivityStartIterator(from_vertex);
        auto end = self->graph.getConnectivityEndIterator(from_vertex);
        for(; it != end; ++it){
            int to_vertex = *it;
            auto& v1 = vertices[from_vertex];
            auto& v2 = vertices[to_vertex];
            CGContextBeginPath(ctx);
            CGContextMoveToPoint(ctx, v1[0], v1[1]);
            CGContextAddLineToPoint(ctx, v2[0], v2[1]);
            CGContextStrokePath(ctx);
            CGContextClosePath(ctx);
        }
    }
    
}

- (void) drawScene {
    
    // get graphics context for the scene
    CGContextRef ctx = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
    
    // set the background
    CGContextSetRGBFillColor (ctx, 1, 1, 1, 1);
    CGContextFillRect (ctx, self.frame);
    
    // draw the graph
    [self drawGraph: ctx];
    
    // update the graph
    sim::version2::multibody_sim( self->graph, self->sim_traits );
}

- (void)animateOneFrame
{
    [self drawScene];
}

- (BOOL)hasConfigureSheet
{
    return NO;
}

- (NSWindow*)configureSheet
{
    return nil;
}


@end
