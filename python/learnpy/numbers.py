# 创建数值列表
for value in range(1,5):
	print(value)

# list函数
numbers = list(range(1,6))
print(numbers)

# 指定步长
even_numbers = list(range(2,11,2))
print(even_numbers)

# 创建1-10的平方的列表
squares = []
for value in range(1,11):
	square = value ** 2
	squares.append(square)
print(squares)
# 代码简化
squares2 = []
for value in range(1,11):
	squares2.append(value**2)
print(squares2)
# 列表解析，进一步简化代码
squares3 = [value**2 for value in range(1,11)]
print(squares3)

# 列表的简单统计
digits = list(range(0,10))
print(digits)
print(min(digits))
print(max(digits))
print(sum(digits))