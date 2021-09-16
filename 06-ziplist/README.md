# ziplist -- 压缩列表

https://redisbook.readthedocs.io/en/latest/compress-datastruct/ziplist.html

Ziplist 是由一系列特殊编码的内存块构成的列表，一个ziplist可以包含多个节点（entry），每个节点可以保存一个长度受限的字符数组（不以 \0 结尾的 char 数组）或者整数

* 字符数组  
  + 长度小于等于 63 （[Math Processing Error]）字节的字符数组
  + 长度小于等于 16383 （[Math Processing Error]） 字节的字符数组
  + 长度小于等于 4294967295 （[Math Processing Error]）字节的字符数组

* 整数  
  + 4 位长，介于 0 至 12 之间的无符号整数
  + 1 字节长，有符号整数
  + 3 字节长，有符号整数
  + int16_t 类型整数
  + int32_t 类型整数
  + int64_t 类型整数



![avatar](../images/zset.svg)

## 编码的选择
在通过 ZADD 命令添加第一个元素到空 key 时， 程序通过检查输入的第一个元素来决定该创建什么编码的有序集。

如果第一个元素符合以下条件的话， 就创建一个 REDIS_ENCODING_ZIPLIST 编码的有序集：

服务器属性 server.zset_max_ziplist_entries 的值大于 0 （默认为 128 ）。
元素的 member 长度小于服务器属性 server.zset_max_ziplist_value 的值（默认为 64 ）。
否则，程序就创建一个 REDIS_ENCODING_SKIPLIST 编码的有序集。

## 编码的转换
对于一个 REDIS_ENCODING_ZIPLIST 编码的有序集， 只要满足以下任一条件， 就将它转换为 REDIS_ENCODING_SKIPLIST 编码：

ziplist 所保存的元素数量超过服务器属性 server.zset_max_ziplist_entries 的值（默认值为 128 ）
新添加元素的 member 的长度大于服务器属性 server.zset_max_ziplist_value 的值（默认值为 64 ）
ZIPLIST 编码的有序集
当使用 REDIS_ENCODING_ZIPLIST 编码时， 有序集将元素保存到 ziplist 数据结构里面。

其中，每个有序集元素以两个相邻的 ziplist 节点表示， 第一个节点保存元素的 member 域， 第二个元素保存元素的 score 域。

多个元素之间按 score 值从小到大排序， 如果两个元素的 score 相同， 那么按字典序对 member 进行对比， 决定那个元素排在前面， 那个元素排在后面。