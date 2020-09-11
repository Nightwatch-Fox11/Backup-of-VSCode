# 第三章 类基础知识
## 第一节 java类基础和main函数
1. 类名和文件名相同  
    ```
    public class Integer
    //此文件必须保存为Integer.java
    ```
2. main函数的写法是固定的，任一不可省略
    ```
    public static void main(String[ args])
    //PSVM
    ```
3. 注释同C语言
4. 一个java文件可多个class，但只能有一个public class,且其名字必须与文件名字完全一样。
5. `System.out.print` 输出  
`System.out.println` 换行输出
6. 类仅由成员变量，成员方法构成
7. 一个class最多有1个main函数，可以没有。main函数不算成员函数
8. 配置里面Program arguments可以提供main函数参数

## 第二节 基本运算类型
1. 布尔类型 `boolean`
2. 字节类型byte，[-128, 127]

## 第四节 函数
1. 修饰词有`public`, `static`, 返回值有 int 或者 void ,一般情况下 public 。
2. 函数重载, 两个函数名字相同，形参不同

# 第四章 面向对象和类
1. `A obj = new A();`
2. 对象赋值是Reference赋值(类似于指针)，基本类型是直接值赋值
3. 注意new出对象后内部属性值的默认值
4. 构造函数名和类名必须一致，构造函数无返回值
5. 一个类可以有多个构造函数，只要形参不同
6. 信息隐藏定义。
7. 自动生成getter， setter。
8. 注意使用this指针时形参的优先级,this的多种用法，构造函数，本类成员等

# 第五章 继承接口抽象类多态
1. 本类方法优先级 > 父类
2. 构造函数第一句话super()
3. 抽象类, abstract,接口, interface ~ implement
4. extend 必须在implement之前
5. 抽象类可以有部分方法实现，接口里面所有方法不能实现
6. 一个类只能继承一个类，但可以实现多个接口。
7. 接口可以继承多个接口。
8. 接口没有main，没有构造函数，都是public不能有private/protected
9. 子类可以转化为父类(大转小)，子类方法优先级高于父类
10. 多态的作用(1)以统一的接口来调用同一类中不同对象的行为
11. 契约设计
12. 在特殊情况下，可以new接口，但是相当于定义了一个匿名类，只能使用一次

# 第六章 final、static和常量设计
1. static的静态方法只能使用静态变量。static在内存中只有一个拷贝
2. 用类名不可以直接引用非静态方法。
3. static块>匿名块>构造函数。
4. static块只有在类第一次被加载时调用。
5. 单例模式中private，一个类在内存空间中只能有一个对象
6. final关键字，final class不可有子类，父类的fianl方法子类不能改写，final变量不可被修改，final修饰对象实例，不能修改其指针(改变指向)，但能修改对象内部值。
7. 子类方法和父类方法名字相同，形参列表也相同就是重写，形参列表不同就是重载
8. 常量定义public ststic final。
9. 接口里面定义的变量默认为常量。
10. 常量设计与常量池

# 第七章 package import classpath
1. 所有Java类放在同一目录下，互相调用无需显式声明
2. import放在package后面，类定义前面
3. jar文件实际上说一组class文件的压缩