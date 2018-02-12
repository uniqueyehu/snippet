age = 16
if age >= 18:
	print("You are old enough to vote!")
	print("Have you registered to vote yet?")
else:
	print("Sorry, you are too young to vote.")
	print("Please register to vote as soon as you turn 18!")

age2 = 64
# if age2 < 4:
# 	print("Your admission cost is $0.")
# elif age2 < 18:
# 	print("Your admission cost is $5.")
# else:
# 	print("Your admission cost is $10.")
# 简化版
if age2 < 4:
	price = 0
elif age2 < 18:
	price = 5
elif age2 < 65:
	price = 10
elif age2 >= 65:
	price = 5
print("Your admission cost is $" + str(price) +".")