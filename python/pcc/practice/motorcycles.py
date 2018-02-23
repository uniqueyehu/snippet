# list
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

# 修改元素
motorcycles[0] = 'ducati'
print(motorcycles)


# 增加元素
# 尾部添加 append
motorcycles[0] = 'honda'
motorcycles.append('ducati')
print(motorcycles)
# 动态创建list
motorcycles2 = []
motorcycles2.append('honda')
motorcycles2.append('yamaha')
motorcycles2.append('suzuki')
print(motorcycles2)

# 任意位置添加 insert
motorcycles2.insert(2, 'ducati')
print(motorcycles2)


# 删除元素
# 删除指定元素 del语句
del motorcycles2[2]
print(motorcycles2)
# pop()
popped_motorcycle = motorcycles2.pop()
print(popped_motorcycle)
print(motorcycles2)
# 根据值来删除 remove()
motorcycles2.remove('honda')
print(motorcycles2)