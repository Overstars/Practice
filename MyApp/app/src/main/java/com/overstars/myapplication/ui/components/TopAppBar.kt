package com.overstars.myapplication.ui.components

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.platform.LocalDensity
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.overstars.myapplication.ui.theme.Blue200
import com.overstars.myapplication.ui.theme.Blue700

@Composable
fun TopAppBar(statusBarHeight: Int, content: @Composable () -> Unit) {

    // 标题栏高度
    val appbarHright = 56.dp

    // 状态栏高度转为dp
    val statusBarHeightDp = with(LocalDensity.current) {
        statusBarHeight.toDp()
    }

    Row (
        modifier = Modifier
            .fillMaxWidth()
            .background (
                Brush.linearGradient(
                    listOf(
                        Blue700,
                        Blue200
                    )
                )
            )
            .height(appbarHright + statusBarHeightDp),
        horizontalArrangement = Arrangement.Center,
        verticalAlignment = Alignment.CenterVertically
    ) {
        content()
    }
}

@Preview
@Composable
fun TopAppBarPreview() {
    TopAppBar(30) {
        Text(text = "标题")
    }
}