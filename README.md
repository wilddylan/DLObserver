# DLObserver
DLObserver For Easier KVO

>1.基本用于Model的监听, 如需扩展需要自己处理 <br>2.请对属性或者全局变量进行监听, 以免局部对象被释放造成奔溃

使用说明：

使用DLBind扩展宏进行增加监听, 使用DLDraw扩展宏来撤销监听。

如果你想监听一个Model的text属性, 那么就直接DLBind(对象, 属性) `subScribeBlock：`当有新的Value的时候就会调用这个Block.

如果你想移除监听, 那么直接使用DLDraw即可。

> [DLBind(_DLLabel, text) subScribeBlock:^(id value) {<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NSLog(@"Label: %@", value);<br>}];

```objc

    [DLBind(_DLLabel, text) subScribeBlock:^(id value) {
        
        NSLog(@"Label: %@", value);
    }];
    
    [DLBind(_DLTextField, text) subScribeBlock:^(id value) {
       
        NSLog(@"TextField: %@", value);
        
        _DLLabel.text = value;
    }];
    
    // Label
    
    _DLLabel.text = @"Hello, Dylan";
    
    // TextField
    
//    _DLTextField.text = @"Hello, Dylan (TextField)";
    
    newModel = [[DLModel alloc] init];
    
    [DLBind(newModel, name) subScribeBlock:^(id value) {
       
        NSLog(@"%@", value);
    }];
    
    newModel.name = @"B_Student";

    DLDraw(newModel, name);
    
    newModel.name = @"C_Student";
```

如果想使用的话, Git地址在这里[DLObserver](https://github.com/WildDylan/DLObserver)
