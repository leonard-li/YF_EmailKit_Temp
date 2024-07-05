//
//  YFEmailInfo.h
//  YFEmailKit
//
//  Created by leonard.li on 2024/6/12.
//

#import <Foundation/Foundation.h>
@class MailItem;

NS_ASSUME_NONNULL_BEGIN

@interface YFEmailInfo : NSObject<NSCoding>

@property (assign, nonatomic) uint64_t emailId; // 邮件id
@property (copy, nonatomic) NSString *sendFrom; // 发送者
@property (assign, nonatomic) uint32_t type; // 邮件类型，0文本，1微信礼包，2互赠礼包，3关注公众号礼包，4签到礼包
@property (assign, nonatomic) uint32_t status; // 邮件状态，0未读，1已读/已领取
@property (copy, nonatomic) NSString *title; // 邮件标题，用于展示在邮箱首页
@property (copy, nonatomic) NSString *content; // 邮件内容，文本邮件：文本；奖励邮件：json字符串
@property (assign, nonatomic) uint64_t sendAt; // 发送时间，Unix秒级时间戳

+ (instancetype)emailWithInfo:(MailItem *)mailInfo;

@end

NS_ASSUME_NONNULL_END
