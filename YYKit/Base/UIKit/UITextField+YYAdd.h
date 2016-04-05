//
//  UITextField+YYAdd.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 14/5/12.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

/**
 Provides extensions for `UITextField`.
 */
@interface UITextField (YYAdd)

/**
 Set all text selected.
 选择所有文本
 */
- (void)selectAllText;

/**
 Set text in range selected.
 设置文本选择的范围
 @param range  The range of selected text in a document.
 */
- (void)setSelectedRange:(NSRange)range;

@end
