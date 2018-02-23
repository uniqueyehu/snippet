import json

# username = input("What is your name? ")

# filename = 'username.json'
# with open(filename, 'w') as f_obj:
# 	json.dump(username, f_obj)
# 	print("We'll remember you when you come back, " + username + "!")

# 重构代码
def get_stored_username():
	"""如果存储了用户名，就获取它"""
	filename = 'username.json'
	try:
		with open(filename) as f_obj:
			username = json.load(f_obj)
	except FileNotFoundError:
		return None
	else:
		return username

def get_new_username():
	"""提示用户输入用户名"""
	username = input("What is your name? ")
	filename = 'username.json'
	with open(filename, 'w') as f_obj:
		json.dump(username, f_obj)
	return username

def greet_user():
	"""问候用户，并指出其名字"""
	username = get_stored_username()
	if username:	# 文件存在，读取用户名
		print("Welcome back, " + username + "!")
	else:			# 文件不存在，获取新的用户名
		username = get_new_username()
		print("We'll remember you when you come back, " + username + "!")

greet_user()