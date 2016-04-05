//
//  UIBezierPath+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 14/10/30.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

/**
 Provides extensions for `UIBezierPath`. ///贝塞尔曲线路径
 */
@interface UIBezierPath (YYAdd)

/**
 Creates and returns a new UIBezierPath object initialized with the text glyphs
 generated from the specified font.
  创建并返回一个新的UIBezierPath对象 初始化指定字体的文本。
 
 @discussion It doesnot support apple emoji. If you want get emoji image, try
 [UIImage imageWithEmoji:size:] in `UIImage(YYAdd)`.
  不支持苹果emoji表情  如果想获取emoji 可以入手UIImage(YYAdd)分类里的[UIImage imageWithEmoji:size:]这个方法

 @param text The text to generate glyph path. 文本生成字形的路径

 @param font The font to generate glyph path. 字体生成字形的路径
 
 @return A new path object with the text and font, or nil if an error occurs.
 */
+ (UIBezierPath *)bezierPathWithText:(NSString *)text font:(UIFont *)font;

@end
