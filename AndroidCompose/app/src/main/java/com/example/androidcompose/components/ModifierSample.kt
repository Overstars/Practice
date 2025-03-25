package com.example.androidcompose.components

import android.util.Log
import androidx.compose.foundation.background
import androidx.compose.foundation.border
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.padding
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun ModifierSample() {
    // 创建一个Text组件，文本内容为"Hello World"
    Text(text = "Hello World",
        // 设置文本样式为红色
        style = TextStyle(Color.Red),
        // 设置组件的修饰符
        modifier = Modifier
            // 设置背景颜色为蓝色
            .background(Color.Blue)
            // 设置内边距为8dp
            .padding(8.dp)
            // 设置边框颜色为绿色，宽度为1dp
            .border(1.dp, Color.Green)
            // 设置点击事件，点击时打印日志
            .clickable {
                Log.i("ModifierSample", "Clicked")
            }
    )
}

@Preview(showBackground = true, showSystemUi = true)
@Composable
fun ModifierSamplePreview() {
    ModifierSample()
}