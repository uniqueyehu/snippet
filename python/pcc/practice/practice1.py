# 循环打印1-20
for i in range(1,21):
	print(i)

# 计算1-1000000总和
digits = range(1,1000001)
print(max(digits))
print(min(digits))
print(sum(digits))

# 打印1-20的奇数
odds = range(1,21,2)
for odd in odds:
	print(odd)

# 3-30内能被3整除的数字
multiples = [value*3 for value in range(1,11)]
for i in multiples:
	print(i)

# 列表解析创建1-10的立方
cubes = [value**3 for value in range(1,11)]
for i in cubes:
	print(i)