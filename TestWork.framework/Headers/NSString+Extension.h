//
//  NSString+Extension.h
//  TestDemo
//
//  Created by ZL on 15/11/29.
//  Copyright © 2015年 ZL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface NSString (Extension)
/**
 *  转化字符串
 *
 *  @param object
 *
 *  @return 
 */
NSString *convertToString(id object);
/**
 *   获取文件路径
 *
 *  @param fileName
 *
 *  @return
 */
NSString* getDocumentsFilePath(const NSString* fileName);
/**
 *  判断文件是否存储
 *
 *  @param filePath
 *
 *  @return 
 */
BOOL checkPathAndCreate(NSString *filePath);
/**
 *  计算大小
 *
 *  @param font 字体大小
 *  @param maxW 显示最大宽度
 *
 *  @return
 */
- (CGSize)sizeWithFont:(UIFont *)font maxW:(CGFloat)maxW;
/**
 *  计算大小
 *
 *  @param font 字体大小
 *
 *  @return
 */
- (CGSize)sizeWithFont:(UIFont *)font;

/**
 *  将十六进制的编码转为emoji字符
 */
+ (NSString *)emojiWithIntCode:(int)intCode;

/**
 *  将十六进制的编码转为emoji字符
 */
+ (NSString *)emojiWithStringCode:(NSString *)stringCode;

- (NSString *)emoji;

/**
 *  是否为emoji字符
 */
- (BOOL)isEmoji;
@end
