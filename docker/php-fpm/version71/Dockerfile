FROM php:7.1-fpm

# 更新包仓库并安装必需的依赖
RUN apt-get update && apt-get install -y \
        libcurl4-openssl-dev \
        curl \
    && rm -rf /var/lib/apt/lists/*  # 清理缓存以减小镜像大小

# 安装pdo_mysql和curl PHP扩展
RUN docker-php-ext-install pdo_mysql \
    && docker-php-ext-install curl

# 安装xdebug
RUN pecl install xdebug-2.9.8 \
    && docker-php-ext-enable xdebug

# 添加Xdebug配置
#RUN echo "xdebug.remote_enable=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_host=host.docker.internal" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_port=9003" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_autostart=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini
