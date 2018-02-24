import pygame.font

class Button():

	def __init__(self, ai_settings, screen, msg):
		self.screen = screen
		self.screen_rect = screen.get_rect()

		# 设置按钮的尺寸和其他属性
		# self.width, self.height = 200, 50
		# self.button_color = (0, 255, 0)
		# 貌似有问题，不能用文字？？？
		# self.text_color = (255, 255, 255)
		# self.font = pygame.font.SysFont("arial", 48)

		# 创建按钮的rect对象，并使其居中
		self.image = pygame.image.load('images/button.png')
		self.rect = self.image.get_rect()
		# self.rect = pygame.Rect(0, 0, self.width, self.height)
		self.rect.center = self.screen_rect.center

		# 按钮的标签只需创建一次
		# self.prep_msg(msg)

	# def prep_msg(self):
	# 	self.msg_image = self.font.render(msg, True, self.text_color, self.button_color)
	# 	self.msg_image_rect = self.msg_img.get_rect()
	# 	self.msg_image_rect.center = self.rect.center

	def draw_button(self):
		# self.screen.fill(self.button_color, self.rect)
		# self.screen.blit(self.msg_image, self.msg_image_rect)
		self.screen.blit(self.image, self.rect)