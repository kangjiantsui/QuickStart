FROM php:7.1-fpm

# 安装pdo_mysql,数据库驱动
RUN docker-php-ext-install pdo_mysql

## 安装xdebug
#RUN pecl install xdebug-2.9.8 \
#    && docker-php-ext-enable xdebug
#
## 添加Xdebug配置
#RUN echo "xdebug.remote_enable=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_host=host.docker.internal" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_port=9003" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
#    && echo "xdebug.remote_autostart=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini
