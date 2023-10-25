# 定义筐和苹果的数量
total_apples = 36
total_baskets = 12
same_baskets = 5

# 定义各种筐能装的苹果数
small_basket = 1
medium_basket = 2
large_basket = 5

# 循环遍历所有可能的组合
for small in range(total_baskets + 1):
    for medium in range(total_baskets + 1 - small):
        for large in range(total_baskets + 1 - small - medium):
            if small + medium + large == total_baskets:
                apples = small * small_basket + medium * medium_basket + large * large_basket
                if apples == total_apples:
                    if small == same_baskets or medium == same_baskets or large == same_baskets:
                        print(f"小筐: {small}, 中筐: {medium}, 大筐: {large}")
