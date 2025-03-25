package com.example.androidcompose.components

import android.annotation.SuppressLint
import android.util.Log
import androidx.compose.foundation.clickable
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview

@SuppressLint("UnrememberedMutableState")
@Composable
fun StateSample() {
    // 使用remember函数创建一个可变的State对象
    val count = remember {
        mutableStateOf(1)
    }
    // 打印外部的值
    Log.d("========", "外面的值：${count.value}")
    // 创建一个Text组件，点击时count的值加1，并打印新的值
    Text(
        text = "一日${count.value}杀",
        modifier = Modifier.clickable {
            count.value++
            Log.d("========", "杀${count.value}杀杀杀杀杀杀杀杀杀杀杀")
        }
    )
}

@Preview
@Composable
fun StateSamplePreview() {
    StateSample()
}