# redisResourceInAction

### Redis 的全称是什么？
Remote Dictionary Server

### 查询实现类型
object encoding [key]

### [使用redis版本 - 6.2](https://github.com/redis/redis/tree/6.2)

此库的用途是把可以拆解的 redis 数据结构 或 功能一个个用单独文件夹保存，每个文件夹的代码都是可以独立编译并测试执行的

### 拆解出的数据结构：

* sds -- Simple dynamic string  [讲解](http://www.shishao.site/sds-16h4f)

* adlist -- A generic doubly linked list implementation  [讲解](http://www.shishao.site/redis-spkfe)

* dict -- Hash Tables Implementation


### Redis 对象：
* String（字符串）
* Hash（字典 or 哈希）
* List（列表）
* Set（集合）
* Sort Set（有序集合）