# 使用Ubuntu 20.04作为基础镜像
FROM ubuntu:20.04

# 避免在安装过程中出现交互式对话框
ARG DEBIAN_FRONTEND=noninteractive

# 安装依赖项
RUN apt-get update && apt-get install -y \
    autoconf \
    build-essential \
    curl \
    libxml2-dev \
    libssl-dev \
    libcurl4-openssl-dev \
    pkg-config \
    libpng-dev \
    libjpeg-dev \
    libonig-dev \
    libsqlite3-dev \
    libpq-dev \
    git \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# 下载PHP 5.4源代码，解压，编译，安装
RUN curl -SL "http://php.net/get/php-5.4.45.tar.gz/from/this/mirror" -o php-5.4.45.tar.gz \
    && tar -xzf php-5.4.45.tar.gz \
    && cd php-5.4.45 \
    && ./configure --enable-fpm --with-mysqli --with-pdo-mysql --with-openssl --with-zlib --enable-mbstring --with-curl --with-gd --with-jpeg-dir=/usr/include/ \
    && make \
    && make install \
    && make clean

# 安装Xdebug，适配PHP 5.4
RUN pecl install xdebug-2.5.5 \
    && docker-php-ext-enable xdebug

# 复制配置文件到容器中（如果有）
# COPY php.ini /usr/local/lib/
# COPY www.conf /usr/local/etc/php-fpm.d/

# 配置Xdebug（这里应该根据实际情况修改）
RUN echo "zend_extension=$(find /usr/local/lib/php/extensions/ -name xdebug.so)" > /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
    && echo "xdebug.remote_enable=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
    && echo "xdebug.remote_autostart=1" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
    && echo "xdebug.remote_connect_back=0" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
    && echo "xdebug.remote_host=host.docker.internal" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini \
    && echo "xdebug.remote_port=9003" >> /usr/local/etc/php/conf.d/docker-php-ext-xdebug.ini
