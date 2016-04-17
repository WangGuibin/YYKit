//
//  UIImage+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 13/4/4.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

/**
 Provide some commen method for `UIImage`.
 Image process is based on CoreGraphic and vImage.
 */
@interface UIImage (YYAdd)

#pragma mark - Create image
///=============================================================================
/// @name Create image
///=============================================================================

/**
 Create an animated image with GIF data. After created, you can access
 the images via property '.images'. If the data is not animated gif, this
 function is same as [UIImage imageWithData:data scale:scale];
 
 @discussion     It has a better display performance, but costs more memory
                 (width * height * frames Bytes). It only suited to display small 
                 gif such as animated emoticon. If you want to display large gif, 
                 see `YYImage`.
 
 @param data     GIF data. 动态图
 
 @param scale    The scale factor 压缩倍率
 
 @return A new image created from GIF, or nil when an error occurs.
 */
+ (UIImage *)imageWithSmallGIFData:(NSData *)data scale:(CGFloat)scale;

/**
 Whether the data is animated GIF.
 
 @param data Image data
 
 @return Returns YES only if the data is gif and contains more than one frame,  判断是否gif
         otherwise returns NO.
 */
+ (BOOL)isAnimatedGIFData:(NSData *)data;

/**
 Whether the file in the specified path is GIF.
 
 @param path An absolute file path.
 
 @return Returns YES if the file is gif, otherwise returns NO.
 */
+ (BOOL)isAnimatedGIFFile:(NSString *)path;

/**
 Create an image from a PDF file data or path.
 
 @discussion If the PDF has multiple page, is just return's the first page's
 content. Image's scale is equal to current screen's scale, size is same as 
 PDF's origin size.
 
 @param dataOrPath PDF data in `NSData`, or PDF file path in `NSString`.
 
 @return A new image create from PDF, or nil when an error occurs.
 */
+ (UIImage *)imageWithPDF:(id)dataOrPath;

/**
 Create an image from a PDF file data or path.
 
 @discussion If the PDF has multiple page, is just return's the first page's
 content. Image's scale is equal to current screen's scale.
 
 @param dataOrPath  PDF data in `NSData`, or PDF file path in `NSString`.
 
 @param size     The new image's size, PDF's content will be stretched as needed.
 
 @return A new image create from PDF, or nil when an error occurs.
 */
+ (UIImage *)imageWithPDF:(id)dataOrPath size:(CGSize)size;

/**
 Create a square image from apple emoji.
 
 @discussion It creates a square image from apple emoji, image's scale is equal
 to current screen's scale. The original emoji image in `AppleColorEmoji` font 
 is in size 160*160 px.
 
 @param emoji single emoji, such as @"😄".
 
 @param size  image's size.  在图片上加表情  666
 
 @return Image from emoji, or nil when an error occurs.
 */
+ (UIImage *)imageWithEmoji:(NSString *)emoji size:(CGFloat)size;

/**
 Create and return a 1x1 point size image with the given color.
 设置填充色的图片  也就是一张纯颜色的图片 1x1像素点
 @param color  The color.
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 Create and return a pure color image with the given color and size.
 
 @param color  The color.
 @param size   New image's type. 可自定义像素点
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 Create and return an image with custom draw code.
 
 @param size      The image size. 自定义图片大小
 @param drawBlock The draw block.
 block传一个上下文出去  自定义画图
 @return The new image.
 */
+ (UIImage *)imageWithSize:(CGSize)size drawBlock:(void (^)(CGContextRef context))drawBlock;

#pragma mark - Image Info
///=============================================================================
/// @name Image Info
///=============================================================================

/**
 Whether this image has alpha channel. 判断图片有木有阿尔法通道
 */
- (BOOL)hasAlphaChannel;


#pragma mark - Modify Image 改变图片
///=============================================================================
/// @name Modify Image
///=============================================================================

/**
 Draws the entire image in the specified rectangle, content changed with
 the contentMode.  画项目图片在一些特定的矩形框里,内容可以由contentMode来改变
 
 @discussion This method draws the entire image in the current graphics context,  这个方法画图片,是在当前上下文
 respecting the image's orientation setting.  考虑到图片的适应
 In the default coordinate system,系统默认情况下
 images are situated down and to the right of the origin of the specified 
 rectangle. 图片坐落在矩形框的右边
 This method respects any transforms applied to the current graphics
 context, however.这个方法可以利用矩形框 让当前上下文仿射变换
 
 @param rect        The rectangle in which to draw the image. 矩形框
 
 @param contentMode Draw content mode  contentMode
 
 @param clips       A Boolean value that determines whether content are confined to the rect.
 */
- (void)drawInRect:(CGRect)rect withContentMode:(UIViewContentMode)contentMode clipsToBounds:(BOOL)clips;

/**
 Returns a new image which is scaled from this image.
 The image will be stretched as needed.
 
 @param size  The new size to be scaled, values should be positive.
 
 @return      The new image with the given size.
 */
- (UIImage *)imageByResizeToSize:(CGSize)size;

/**
 Returns a new image which is scaled from this image.
 The image content will be changed with thencontentMode.
 
 @param size        The new size to be scaled, values should be positive.
 
 @param contentMode The content mode for image content.
 
 @return The new image with the given size.
 */
- (UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

/**
 Returns a new image which is cropped from this image.
 
 @param rect  Image's inner rect.
 
 @return      The new image, or nil if an error occurs.
 */
- (UIImage *)imageByCropToRect:(CGRect)rect;

/**
 Returns a new image which is edge inset from this image.
 
 @param insets  Inset (positive) for each of the edges, values can be negative to 'outset'.
 
 @param color   Extend edge's fill color, nil means clear color.
 
 @return        The new image, or nil if an error occurs.
 */
- (UIImage *)imageByInsetEdge:(UIEdgeInsets)insets withColor:(UIColor *)color;

/**
 Rounds a new image with a given corner size.
 
 @param radius  The radius of each corner oval. Values larger than half the
                rectangle's width or height are clamped appropriately to half
                the width or height.
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius;

/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.

 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width 
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor;

/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.
 
 @param corners      A bitmask value that identifies the corners that you want
                     rounded. You can use this parameter to round only a subset
                     of the corners of the rectangle.
 
 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width 
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 
 @param borderLineJoin The border line join.
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                              corners:(UIRectCorner)corners
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor
                       borderLineJoin:(CGLineJoin)borderLineJoin;

/**
 Returns a new rotated image (relative to the center).
 
 @param radians   Rotated radians in counterclockwise.⟲
 
 @param fitSize   YES: new image's size is extend to fit all content.
                  NO: image's size will not change, content may be clipped.
 */
- (UIImage *)imageByRotate:(CGFloat)radians fitSize:(BOOL)fitSize;

/**
 Returns a new image rotated counterclockwise by a quarter‑turn (90°). ⤺
 The width and height will be exchanged.
 左转90
 */
- (UIImage *)imageByRotateLeft90;

/**
 Returns a new image rotated clockwise by a quarter‑turn (90°). ⤼
 The width and height will be exchanged.
  右转90
 */
- (UIImage *)imageByRotateRight90;

/**
 Returns a new image rotated 180° . ↻
 旋转180
 */
- (UIImage *)imageByRotate180;

/**
 Returns a vertically flipped image. ⥯
 上下翻转
 */
- (UIImage *)imageByFlipVertical;

/**
 Returns a horizontally flipped image. ⇋
 水平翻转
 */
- (UIImage *)imageByFlipHorizontal;


#pragma mark - Image Effect
///=============================================================================
/// @name Image Effect
///=============================================================================

/**
 Tint the image in alpha channel with the given color.
 
 @param color  The color.
 */
- (UIImage *)imageByTintColor:(UIColor *)color;

/**
 Returns a grayscaled image.
 */
- (UIImage *)imageByGrayscale;

/**
 Applies a blur effect to this image. Suitable for blur any content.
 */
- (UIImage *)imageByBlurSoft;

/**
 Applies a blur effect to this image. Suitable for blur any content except pure white.
 (same as iOS Control Panel)
 */
- (UIImage *)imageByBlurLight;

/**
 Applies a blur effect to this image. Suitable for displaying black text.
 (same as iOS Navigation Bar White)
 */
- (UIImage *)imageByBlurExtraLight;

/**
 Applies a blur effect to this image. Suitable for displaying white text.
 (same as iOS Notification Center)
 */
- (UIImage *)imageByBlurDark;

/**
 Applies a blur and tint color to this image.
 
 @param tintColor  The tint color.
 */
- (UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

/**
 Applies a blur, tint color, and saturation adjustment to this image,
 optionally within the area specified by @a maskImage.
 
 @param blurRadius     The radius of the blur in points, 0 means no blur effect.
 
 @param tintColor      An optional UIColor object that is uniformly blended with
                       the result of the blur and saturation operations. The
                       alpha channel of this color determines how strong the
                       tint is. nil means no tint.
 
 @param tintBlendMode  The @a tintColor blend mode. Default is kCGBlendModeNormal (0).
 
 @param saturation     A value of 1.0 produces no change in the resulting image.
                       Values less than 1.0 will desaturation the resulting image
                       while values greater than 1.0 will have the opposite effect.
                       0 means gray scale.
 
 @param maskImage      If specified, @a inputImage is only modified in the area(s)
                       defined by this mask.  This must be an image mask or it
                       must meet the requirements of the mask parameter of
                       CGContextClipToMask.
 
 @return               image with effect, or nil if an error occurs (e.g. no
                       enough memory).
 */
- (UIImage *)imageByBlurRadius:(CGFloat)blurRadius
                     tintColor:(UIColor *)tintColor
                      tintMode:(CGBlendMode)tintBlendMode
                    saturation:(CGFloat)saturation
                     maskImage:(UIImage *)maskImage;

@end
