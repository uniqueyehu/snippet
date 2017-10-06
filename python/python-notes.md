# 笔记
## 1、Python2.x
raw_input：对所有的输入按照字符串处理，返回字符串

input：输入字符串需要单引号括起来

## 2、数据变量
a = 123

b = 'abc'

## 3、字符串由单双引号括起来
### (1)当字符串中有单引号时，可用双引号括起来。
"I'm OK" --> I'm OK

### (2)使用转义
'I'm\"OK\"!' --> I'm "OK"!

## 4、格式化输出
'Hello, %s' <font color=red>%</font> 'world' --> 'Hello, world'

'%2d-%02d' % (3, 1) --> ' 3-01'

'%.2f' % 3.1415926 --> '3.14'

## 5、list
### (0)定义一个list列表
classmates = ['a', 'b', 'c']
### (1)访问第一个元素
classmates[0] --> 'a'
### (2)访问倒数第二个元素
classmates[<font color=red>-2</font>] --> 'c'
### (3)向尾部追加元素
classmates.append('Adam')
### (4)插入到指定地方
classmates.insert(1, 'Jack')
### (5)删除尾部元素
classmates.pop()
### (6)删除指定元素
classmates.pop(i)
### (7)替换指定位置元素
classmates[1] = 'Sarah'
### (8)类型不同
L = ['Apple', 123, <font color=red>True</font>]
### (9)嵌套
s = ['python', 'java', ['asp', 'php'], 'scheme']

s[2][1] --> 'php'

## 6、tuple
### (1)和list非常类似，但是一旦初始化就不能修改，代码更安全
t = ('a', 'b', 'c')
### (2)一个元素时
t = (1,)
### (3)所指向的元素不能修改，但是如果指向的是list
![py1.png](https://raw.githubusercontent.com/uniqueyehu/blog/master/images/py1.png)

## 7、条件判断和循环
### (1)代码片，用冒号表示
if condition:

&nbsp;&nbsp;&nbsp;&nbsp;xxx

&nbsp;&nbsp;&nbsp;&nbsp;xxx

elif condition<font color=red>:</font>

&nbsp;&nbsp;&nbsp;&nbsp;xxx

&nbsp;&nbsp;&nbsp;&nbsp;xxx

else<font color=red>:</font>

&nbsp;&nbsp;&nbsp;&nbsp;xxx

### (2)for循环
for x <font color=red>in</font> xxx:

&nbsp;&nbsp;&nbsp;&nbsp;xxx

xxx

### (3)while循环
while xxxx:

&nbsp;&nbsp;&nbsp;&nbsp;xxx

xxx

## 8、dict
### (1)相当于c++里的map，key-value对，key不可修改，定义之后会按key排序，但添加时不会重拍序
d = {'Micheal': 95, 'Bob': 75, 'Tracy': 85}

d --> {'Bob': 75, 'Micheal': 95, 'Tracy': 85}
### (2)访问
d['Bob'] --> 75
### (3)添加
d['Adam'] = 76
### (4)删除
d.pop('Bob')
### (5)查找
'Tomas' in d --> False

d.get('Tomas') -->空

d.get('Tomas', -2) --> -2 

## 9、set
### (1)无序、无重复元素的集合
s = set([1, 2, 3])

s --> set([1, 2, 3])
### (2)添加
s.add(5)
### (3)删除
s.remove(1)
### (4)交集、并集操作
s1 & s2

s1 | s2

## 10、函数
### (1)定义函数
def my_abs(x):
if x >= 0:
return x
else:
return -x
### (2)空函数
def nop():
pass
### (3)参数检查
Python会检查参数个数，但不检查参数类型，需要函数自身完成检查
### (4)返回多个值
函数返回多个值时，以tuple形式返回
### (5)默认参数
```
def power(x, y = 1, z = 2):
xxx
power(2) --> power(2, 1, 2)
power(2, 3) --> power(2, 3, 2)
power(2, z = 5) --> power(2, 1, 5)
```
### (6)可变参数
常规调用时，需要传入list或者tuple；使用可变参数，可简化调用方式；可使用list或tuple名字作为参数传入
```
def calc(*numbers):
xxx
calc(1, 2, 3) --> calc([1, 2, 3])
nums = [1, 2, 3, 4]
calc(*nums)
```
### (7)关键字参数
传入关键字参数时，在函数内部自动组装为一个dict；可以将一个dict作为参数传入
```
def person(name, age, **kw):
xxx
person('Bob', 35, city='Beijing') --> name: Bob age: 35 other: {'city': 'Beijing'}
kw = {'city': 'Beijing', 'job': 'Engineer'}
person('Jack', 24, **kw)
```
### (8)参数组合
任意函数，都可以通过`func(*args, **kw)`的形式来调用
参数定义的顺序：必选参数、默认参数、可变参数、关键字参数
```
def func(a, b, c = 0, *args, **kw)
args = (1, 2, 3, 4)
kw = {'x': 99}
func(*args, **kw) --> a = 1, b = 2, c = 3, args = (4,) kw = {'x': 99}
```
### (9)递归函数
```
def fact(n):
if n == 1:
return 1
return n * fact(n - 1)
```

## 11、切片

## 12、迭代
for xxx in xxxx:
print xxx

## 13、列表生成式
运用列表生成式，可以快速生成list

## 14、生成器

## 15、函数式编程

### (1)高阶函数
把函数作为参数传入，这样的函数称为高阶函数

### (2)返回函数

### (3)匿名函数
Python对匿名函数支持有限，只有一些简单的情况下可以使用匿名函数

def f(x):
return x * x
相当于
lambda x: x * x
