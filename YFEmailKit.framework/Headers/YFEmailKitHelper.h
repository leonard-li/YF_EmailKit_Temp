//
//  YFEmailKitHelper.h
//  YFEmailKit
//
//  Created by leonard.li on 2024/6/12.
//

#import <Foundation/Foundation.h>
#import <YFEmailKit/YFEmailInfo.h>

typedef NS_ENUM(uint32_t, YFEmailType) {
    YFEmailTypeText = 0,            // 文本
    YFEmailTypeWechatGift = 1,      // 微信礼包
    YFEmailTypeExchangeGift = 2,    // 互赠礼包
    YFEmailTypeFollowGift = 3,      // 关注公众号礼包
    YFEmailTypeSignInGift = 4       // 签到礼包
};

NS_ASSUME_NONNULL_BEGIN

@interface YFEmailKitHelper : NSObject

@property (class, nonatomic, readonly) YFEmailKitHelper *defaultHelper;

/// 业务标识
@property (nonatomic, strong) NSString *bid;

/// 获取邮件列表
/// @param userId 用户Id
/// @param types 需要获取的邮件类型列表, 示例: NSArray<NSNumber *> * types = @[@(YFEmailTypeText), @(YFEmailTypeWechatGift), @(YFEmailTypeExchangeGift), @(YFEmailTypeFollowGift), @(YFEmailTypeSignInGift)];
/// @param completion 回调结果
- (void)getEmailList:(NSString *)userId
               types:(NSArray<NSNumber *> *)types
          completion:(void(^_Nullable)(NSError * _Nullable error, NSArray<YFEmailInfo *> * _Nullable emailList))completion;

/// 发送邮件
/// @param from 发送者用户Id
/// @param to 接受者用户Id集合
/// @param type 邮件类型，0文本，1微信礼包，2互赠礼包，3关注公众号礼包，4签到礼包
/// @param title 邮件标题，用于展示在邮箱首页
/// @param content 邮件内容，文本邮件：文本；奖励邮件：json字符串
/// @param completion 回调结果
- (void)sendEmail:(NSString *)from
               to:(NSArray<NSString *> *)to
             type:(YFEmailType)type
            title:(NSString *)title
          content:(NSString *)content
       completion:(void(^_Nullable)(NSError * _Nullable error))completion;

/// 删除邮件
/// @param emailIds 邮件Id集合, 示例: NSArray<NSNumber *> * emailIds = @[@(111), @(222), @(333), @(444), @(555)];
/// @param to 接受者用户Id
/// @param completion 回调结果
- (void)deleteEmail:(NSArray<NSNumber *> *)emailIds
                 to:(NSString *)to
         completion:(void(^_Nullable)(NSError * _Nullable error))completion;

/// 设置邮件状态为已读/已领取
/// @param emailIds 邮件Id集合, 示例: NSArray<NSNumber *> * emailIds = @[@(111), @(222), @(333), @(444), @(555)];
/// @param to 接受者用户Id
/// @param completion 回调结果
- (void)setEmailRead:(NSArray<NSNumber *> *)emailIds
                  to:(NSString *)to
          completion:(void(^_Nullable)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
