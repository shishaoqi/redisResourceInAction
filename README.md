# redisResourceInAction

### Redis 的全称是什么
Remote Dictionary Server

### 查询实现类型
object encoding [key]

### 版本
[使用redis版本 - 6.2](https://github.com/redis/redis/tree/6.2)

### 要做什么
此库的用途是把可以拆解的 redis 数据结构 或 功能一个个用单独文件夹保存，每个文件夹的代码都是可以独立编译并测试执行的。编程思想中，有分治策略，那么要源码阅读上，分治策略也是非常有效的方法。在 Redis 源码上，由于其就是由各种数据结构与算法组成，更是有天然的可拆分特性，加上 Redis 源码优美，更加大实现拆解的容易性。

### 此拆解应该是网上唯一的能运行起来的
首先，做下标题的解释：此拆解应该是网上唯一的能运行起来的，指的是拆解后的能以最小单元运行（而不是说精简的 redis 源码）。

只要有源码，就有人以自己的理解去写相应的 XXX 源码分析，随着时间推移，网上就出现一片相关的源码分析。从事编程多年，在阅读一些大型开源项目时，很多时候自己也会有点困惑，自己编程能力行不行，不然怎么为什么不能看懂大型开源项目源码呢？在此先承认自己能力一般吧。好，上句说到众多程序员搞源码研究，分享文章，从而鱼龙混杂，其中有真水平的，也有掺水的。但，不管怎样，如果大型到一定程度的源码，研究点它的凤毛麟角有什么意义呢？所以，除非能以系列文章形式把对应源码从头到尾说全了（或者出书），不然不写也罢。

本库的 Redis 源码分析与拆解，希望不仅做到出从头说到尾的系列，也做到不光看到源码分析，还能动手实操，从而让无数服务运用的 Redis 源码（或其一部分）在你手上进行玩转。

为什么要运行起来？这也许是我的能力一般的问题，因为看到源码在那，往往就觉得认真分析了又如何，能保证实际运行的情况就如你所理解的。太较真的坏是容易放弃阅读源码，太较真的好是找了个法子改变现状并勉强地坚持下去。

### 拆解出的数据结构：

* sds -- Simple dynamic string  [讲解](https://www.shishao.site/sds-16h4f)

* adlist -- A generic doubly linked list implementation  [讲解](https://www.shishao.site/redis-spkfe)

* hash table -- Hash Tables Implementation [讲解](https://www.shishao.site/array-ny42y)

* skip table -- Skip table implementation [讲解](https://www.shishao.site/redis-skiplist-2ywpo)


### Redis 对象：
* String（字符串）
* List（列表）
* Hash（字典 or 哈希）
* Set（集合）
* Sort Set（有序集合）