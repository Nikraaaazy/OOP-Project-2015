# OOP-Project-2015
My first repo

## The Aim
###《面向对象程序设计基础》课程大作业（2015版）

>用计算机来辅助外语学习越来越流行，在互联网或各种手机应用程序商店中能见到很多设计十分优秀的外语学习工具。其中，背记外语单词工具的用户群体最大。
>请针对英语单词背记要求，利用本学期所学面向对象编程的基本思想，充分锻炼和发挥自己的抽象思维能力，基于C++语言的OOP 方法，设计并实现一个功能强大、使用方便、人用人爱（至少能让自己达到喜爱的程度）的英语单词背记工具。

####功能要求：
	• 单词查询、测试、提醒、助记
	• 音标、词性、释义、例句
	• 跨平台（win, linux/mac）
	• 运用记忆遗忘规律
	• 单词类别（已掌握的熟词、不认识的生词、不牢固的“灰词”、等等）
	• 对英语文件自动提取生词并生成生词释义
	• 支持至少一个其他已有单词工具导出的单词数据文件
	• 对指定单词，生成在拼写上有“亲缘”关系的单词关系图
	• 其他你认为合适的功能

####提交要求：
	• 工具使用手册（WORD 或PDF）
	• 程序设计文档（WORD 或PDF）
	• 源程序（CPP、H）、makefile
	• 资源文件（如词典数据）
	• 其他助教检查时规定的提交要求

>大作业要求分组完成，每个小组统一计分，一般由2或3人组成一个小组。特殊情况下要求4人一组的，成绩乘上系数0.9；要求一个人独立完成的，成绩乘上系数0.8。

>最晚第15周周日前提交。前8周内完成并提交的，大作业成绩乘上系数1.2；在第12周末之前完成并提交的，大作业成绩乘上系数1.1。在第16周到期末考试前之间完成并提交的，成绩乘上系数0.9；期末考试之后提交的，成绩乘上系数0.5。
>允许多次提交，但后续提交要附上一份说明文档，详细说明与前一版本在设计与实现上的改动。多次提交的，以最后一次提交的版本成绩为最终成绩，计分时依然要按提交时间把大作业成绩乘上系数。

## 开发日志

### Day 1

- 创建 word.h word.cpp 正式开工
- 加入[Moby Project](http://icon.shef.ac.uk/Moby/) 其中：
	- mhyph 为重音标记文件
	- mpos 为词性标记文件
	- mpron 为音标文件
	- mthes 为同根词文件
	   
	具体见文件内readme
- 加入经简单预处理的字典 word.txt，格式如下（数字代表行）：
	1. 词
	2. 变形（如单复数，分词）若有多个释义会以数字标记
	3. 解释
	4. 例句（数量范围[0,n]）
	5. 词性
	   
	词条间由空行分隔
	   
	注：部分格式可能仍存在问题

### Day 2

- 处理DictFile为Output.txt:
	- 第一行为单词
	- 第二行为解释
	- 第三行为熟练度（初识为0）
	- 两个单词之间以换行分隔

- 生成Word类:
	友元:
	- WordCollection类
	私有成员变量:
	- word 单词
	- all 音标解释例句
	- wordLevel 熟练度
	公有方法：
	- 初始化函数，接string, string, int
	- 拷贝构造函数
	- 返回成员变量的三个函数
	- 设定wordLevel
	- 重载 == 算符，只要word相等就返回true

- 生成WordCollection类:
	私有成员变量:
	- vector<Word*>
	公有方法:
	- 初始化函数
	- 拷贝构造函数
	- 析构函数

### Day 3

- 修改了WordCollection类：
	增加一个WordCollection指针名为instance负责管理读入的所有单词；新增getWordCollection、push、size、isEmpty、next函数便于测试时进行单词管理。

- WordCollectionFactory
	新增了WordCollectionFactory类负责创建测试时所使用的单词集合。

- WordTest

### Day 4

- 完成了UI 查询 学习 提取功能
	- 新增UI.cpp，管理程序界面
	- 新增WordExtraction类，负责对文件提取生词并将释义输出到新文件
	- debug: 修改了词库，将大写转换为小写
	- 支持大写输入
	- 支持对提取文件单词的判重

