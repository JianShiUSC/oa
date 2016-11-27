/*
一个处理器要处理一堆request，一次只能处理一条，如果它有几个积压着的requests，它会先执行持续时间短的那个；
对于持续时间相等的requests，先执行最早到达处理器的request。问平均每个request要等多久才能被处理。
input：requestTimes[]，每个request到达处理器的时间; durations[] 每个request要处理的持续时间。 两个数组是一一对应的，并已按requestTimes[] 从小到大排序过
*/
