//
//  NSThread+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/7/3.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

@interface NSThread (YYAdd)

/**
 Add an autorelease pool to current runloop for current thread.
 加一个自动释放池到当前的运行循环
 @discussion If you create your own thread (NSThread/pthread), and you use 
 runloop to manage your task, you may use this method to add an autorelease pool 如果你创建了自己的线程,你还想用runloop管理你的任务, 使用这个方法 , 你可以添加一个自动释放池
 to the runloop. Its behavior is the same as the main thread's autorelease pool. 
 它的一切行为 会像主线程一样 自动释放...
 */
+ (void)addAutoreleasePoolToCurrentRunloop;

@end
