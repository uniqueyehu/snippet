# 字符串
# "" or '' 中包含的字符串

name = "ada lovelace"
# 以首字母大写的方式显示每个单词
print(name.title())
# 说明字符串本身没变
print(name)

name = "Ada Lovelace"
# 全部大写显示
print(name.upper())
# 全部小写显示
print(name.lower())

# 字符串拼接
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name
print(full_name)
print("Hello, " + full_name.title() + "!")

# 制表符、换行符
print("Languages:\n\tPython\n\tC\n\tJavaScript")

# 删除字符串开头和结尾空白
favorite_language = ' python '
print(favorite_language)
# 删除左边空白
print(favorite_language.lstrip())
# 删除右边空白
print(favorite_language.rstrip())
# 删除两端空白
print(favorite_language.strip())