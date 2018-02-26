# 基本知识

# 外星人入侵游戏

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
2. 将数据列表传递给函数plt.plot(xlist, ylist, ...)
3. 设置图标标题，设置坐标轴，刻度标记等：plt.title(...)，plt.xlabel(...)，plt.ylabel(...)，plt.tick_params(...)
4. 打开matplotlib查看器，并显示绘制的图形：plt.show()
5. 示例：data_visualization/mpl_squares.py

### 绘制散点图



## Pygal