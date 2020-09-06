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
3. 注意new出对象后内部属性值的默认是