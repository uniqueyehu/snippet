# 列表list的排序
cars = ['bmw', 'audi', 'toyota', 'subaru']
# 永久性排序
cars.sort()
print(cars)
cars.sort(reverse=True)
print(cars)

# 临时排序
cars2 = ['bmw', 'audi', 'toyota', 'subaru']
print(sorted(cars2))
print(cars2)

# 倒序打印list
cars2.reverse()
print(cars2)
cars2.reverse()
print(cars2)

# 获取长度
print(len(cars2))