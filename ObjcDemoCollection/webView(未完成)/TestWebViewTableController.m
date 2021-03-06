//
//  TestWebViewTableController.m
//  ObjcDemoCollection
//
//  Created by jiabaozhang on 2018/5/18.
//  Copyright © 2018年 jiabaozhang. All rights reserved.
//

#import "TestWebViewTableController.h"
#import "BaseTableViewCell.h"
#import "BaiduWebViewController.h"


@interface TestWebViewTableController ()

@end

@implementation TestWebViewTableController


- (void)viewDidLoad
{
    [super viewDidLoad];
    self.items = @[
                   @{@"title" : @"01-biadu", @"controller" : [[BaiduWebViewController alloc] init]},
                   ].mutableCopy;
}

#pragma mark ## tableView methods ##
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    BaseTableViewCell *cell = [BaseTableViewCell cellWithTableView:tableView];
    cell.nameLabel.text = [[self.items objectAtIndex:indexPath.row] valueForKey:@"title"];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    [self pushViewControllerWithIndexPath:indexPath];
}


@end
