/*
 * locked : 1锁定，0可变

 */
fun canBeValid(s: String, locked: String): Boolean {
    var ans = true
    var cnt = 0
    val len = s.length

    return ans
}

fun main(args: Array<String>) {
    val str = readLine()!! // 读入一行字符串
    val locked = readLine()!! // 读入一行字符串
    println(canBeValid(str, locked))
}
