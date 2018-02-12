favorite_languages = {
	'jen': 'python',
	'sarah': 'c',
	'edward': 'ruby',
	'phil': 'python',
}

print("Sarah's favorite language is " +
	favorite_languages['sarah'].title() +
	".")

print("------")
# 遍历字典中的键值对
for name, language in favorite_languages.items():
	print(name.title() + "'s favorite language is " +
		language.title() + ".")

print("------")
# 遍历字典中所有的键
for name in favorite_languages.keys():
	print(name.title())

print("------")
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
	print(name.title())

	if name in friends:
		print(" Hi " + name.title() +
			", I see your favorite language is " +
			favorite_languages[name].title() + "!")

print("======")
# 按顺序遍历字典中的键
for name in favorite_languages.keys():
	print(name.title() + ", thank you for taking the poll.")
print("")
# 排序
for name in sorted(favorite_languages.keys()):
	print(name.title() + ", thank you for taking the poll.")

print("++++++")
# 遍历字典中的值
print("The following language have been mentioned:")
for language in favorite_languages.values():
	print(language.title())
print("")
# 去除重复
for language in set(favorite_languages.values()):
	print(language.title())