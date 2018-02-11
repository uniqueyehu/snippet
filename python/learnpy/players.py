# list 切片
players = ['charles', 'martina', 'micheal', 'florence', 'eli']
print(players[0:3])
print(players[1:4])

# 从 list 首部开始，省略开头索引
print(players[:4])
# 一直到 list 尾部，省略终止索引
print(players[2:])
# 使用负值索引
print(players[-3:])
# 开头、终止索引均省略
print(players[:])

# 遍历切片
print("Here are the first three players on my team:")
for player in players[:3]:
	print(player.title())

# 复制列表
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]

my_foods.append('cannoli')
print("My favorite foods are :")
print(my_foods)

friend_foods.append('ice cream')
print("\nMy friend's favorite foods are:")
print(friend_foods)

# 关联指向
my_foods2 = ['pizza', 'falafel', 'carrot cake']
friend_foods2 = my_foods2

my_foods2.append('cannoli')
print("\n\nMy favorite foods are :")
print(my_foods2)

print("\nMy friend's favorite foods are:")
print(friend_foods2)


# 元组
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])

# 修改元组的值，不可更改，除非重新定义一个。。。
# dimensions[0] = 250
dimensions = (400, 100)
for dimension in dimensions:
	print(dimension)