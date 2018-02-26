# 超级基本知识
## 变量和简单数据类型

## 列表
for循环遍历列表、range()函数、列表切片、复制列表、元组
```
# 列表
digits = [1, 2, 3, 4, 5]

# 元组
dimensions = (200, 50)
```

## if语句
if-else语句、if-elif-else语句

## 字典
使用字典、遍历字典
```
alien_0 = {'color': 'green', 'points': 5}
```

## 用户输入和while循环
input()函数、while循环处理列表和字典

## 函数
定义函数、传递参数、返回值、传递任意数量的实参、将函数存储在模块中

## 类
创建和使用类、继承、导入类、标准库的使用

## 文件和异常
打开文件、读文件、写文件、异常处理try-except-else、使用json格式存储数据

## 测试代码
测试函数、测试类

# 外星人入侵游戏
## Pygame

# 数据可视化
## matplotlib
在OS X系统中安装matplotlib
```
pip3 install --user matplotlib
```

测试matplotlib是否安装成功，使用python3启动一个终端命令会话框，再尝试导入matplotlib
```
import matplotlib
```

matplotlib的使用
[https://matplotlib.org]

### 绘制折线图
1. 导入模块：`import matplotlib.pyplot as plt`
2. 将数据列表传递给函数`plt.plot(xlist, ylist, ...)`
3. 设置图标标题，设置坐标轴，刻度标记等：`plt.title(...)，plt.xlabel(...)，plt.ylabel(...)，plt.tick_params(...)`
4. 打开matplotlib查看器，并显示绘制的图形：`plt.show()`
5. 示例：`data_visualization/mpl_squares.py`

### 绘制散点图
1. 导入模块：`import matplotlib.pyplot as plt`
2. 将数据列表传递给函数`plt.scatter(xlist, ylist, ...)`
3. 设置图标标题，设置坐标轴，刻度标记等：`plt.title(...)，plt.xlabel(...)，plt.ylabel(...)，plt.tick_params(...)`
4. 打开matplotlib查看器，并显示绘制的图形：`plt.show()`
5. 示例：模拟*随机漫步*：`data_visualization/rw_visual.py random_walk.py`

## Pygal
安装Pygal：
```
pip3 install --user pygal
```

Pygal的使用
[https://www.pygal.org]

### 绘制条形图
1. 导入模块：`import pygal`
2. 创建一个pygal.Bar()实例：`hist = pygal.Bar()`
3. 设置图表标题，x轴数据标签，x轴标题，y轴标题等属性：`hist.title(...), hist.x_labels(...), hist.x_title(...), hist.y_title(...)`
4. 将一系列值（图例，y轴数据）添加到图表中：`hist.add('D6', values)`
5. 将图表渲染为一个SVG文件，可用Web浏览器查看：`hist.render_to_file(filename)`
6. 示例：模拟掷骰子：`data_visualization/die_visual.py`

## 分析CSV文件
以逗号分隔的文本文件：CSV
1. 导入csv模块：`import csv`
2. 打开文件：`with open(filename) as f`
3. 创建一个与该文件关联的reader对象：`reader = csv.reader(f)`
4. 读取文件的下一行，数据以列表的形式存在返回值中：`header_row = next(reader)`
   利用循环读取reader中的每行数据：
```
highs = []
for row in reader:
    highs.append(row[1])
```
5. 利用matplotlib将获取的数据进行可视化，分析
6. 示例：绘制气温图表：`data_visualization/highs_low.py`

## 分析json文件
文件格式：
```
[
{"xx": "123"},
{"yy": "456"},
...
]
```
1. 导入模块：`import json`
2. 打开文件：`with open(filename) as f`
3. 将数据加载到列表中：`pop_data = json.load(f)`
4. 读取列表中的字典：
```
for pop_dict in pop_data:
	print(pop_dict['xx'])
	print(pop_dict['yy'])
	...
```
5. 利用Pygal将数据进行可视化，分析
6. 示例：制作世界人口地图：`data_visualization/world_population.py`
使用pygal_maps_world，需要安装