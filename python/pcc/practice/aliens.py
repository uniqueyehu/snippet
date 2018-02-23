# 字典、列表嵌套使用

# 列表中包含字典
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}

aliens = [alien_0, alien_1, alien_2]

for alien in aliens:
	print(alien)

print("------")
aliens2 = []

for alien_number in range(30):
	new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'}
	aliens2.append(new_alien)

for alien in aliens2[:5]:
	print(alien)
print("...")
print("Total number of aliens2: " + str(len(aliens2)))

print("======")
for alien in aliens2[0:3]:
	if alien['color'] == 'green':
		alien['color'] = 'yellow'
		alien['speed'] = 'medium'
		alien['points'] = 10

for alien in aliens2[:5]:
	print(alien)
print("...")