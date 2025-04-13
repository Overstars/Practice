class Solution5 {
    fun countGoodTriplets(arr: IntArray, a: Int, b: Int, c: Int): Int {
        var ans = 0
        for (i in 0 until arr.size) {
            for (j in i + 1 until arr.size) {
                for (k in j + 1 until arr.size) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
                        ans++
                    }
                }
            }
        }
        return ans
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun main(args: Array<String>): Unit {
    val arr = readline_int()
    val (a, b, c) = readInts()
    val solution = Solution5()
    println(solution.countGoodTriplets(arr, a, b, c))
}