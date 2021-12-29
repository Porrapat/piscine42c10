all:
	-$(MAKE) -C ex00 test
	-$(MAKE) -C ex01 test
	-$(MAKE) -C ex02 test
	-$(MAKE) -C ex03 test
	-$(MAKE) -C ex00 fclean
	-$(MAKE) -C ex01 fclean
	-$(MAKE) -C ex02 fclean
	-$(MAKE) -C ex03 fclean