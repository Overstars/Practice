package com.example.androidcompose.layout

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.size
import androidx.compose.material.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.window.Dialog

@Composable
fun DialogSample() {

    // 定义一个布尔类型的可变状态，用于控制对话框的显示与隐藏
    var showDialog by remember { mutableStateOf(false) }

    // 创建一个垂直布局
    Column() {
        // 创建一个按钮，点击时将showDialog设置为true，显示对话框
        Button(
            onClick = {
                showDialog = true
            }
        ) {
            // 在按钮上显示文本
            Text(text = "Show Dialog")
        }
        // 如果showDialog为true，则显示对话框
        if (showDialog) {
            // 创建一个对话框
//            Dialog(
//                onDismissRequest = { showDialog = false }
//            ) {
//                // 创建一个白色背景的表面
//                Surface (
//                    color = Color.White,
//                    modifier = Modifier.size(
//                        width = 200.dp,
//                        height = 200.dp
//                    )
//                ) {
//                    // 在表面上创建一个垂直布局
//                    Column() {
//                        // 在垂直布局中显示文本
//                        Text(text = "Hello Dialog")
//                    }
//                }
//
//            }

            // 创建一个对话框，带按钮的
            AlertDialog(
                onDismissRequest = {
                    // 点击对话框外部或点击取消按钮时，将showDialog设置为false，隐藏对话框
                    showDialog = false
                },
                title = {
                    // 在对话框中显示标题
                    Text(text = "Dialog Title")
                },
                confirmButton = {
                    // 创建一个确认按钮
                    TextButton(onClick = {
                        // 点击确认按钮时，将showDialog设置为false，隐藏对话框
                        showDialog = false
                    }) {
                        // 在确认按钮上显示文本
                        Text(text = "Confirm")
                    }
                },
                dismissButton = {
                    // 创建一个取消按钮
                    TextButton(onClick = {
                        // 点击取消按钮时，将showDialog设置为false，隐藏对话框
                        showDialog = false
                    }) {
                        // 在取消按钮上显示文本
                        Text(text = "Dismiss")
                    }
                },
                text = {
                    // 在对话框中显示文本
                    Text(text = "这是 Dialog Text")
                }
            )
        }
    }


}

@Preview
@Composable
fun DialogSamplePreview() {
    DialogSample()
}