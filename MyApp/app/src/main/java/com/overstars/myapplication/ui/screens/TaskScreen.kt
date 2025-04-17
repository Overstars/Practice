package com.overstars.myapplication.ui.screens

import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview

// 定义一个Composable函数，用于显示任务内容
@Composable
fun TaskScreen() {
    // 在屏幕上显示文本"Task Content."
    Text(text = "Task Content.")

}

@Preview
@Composable
fun TaskScreenPreview() {
    TaskScreen()
}