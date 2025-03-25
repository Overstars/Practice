package com.example.androidcompose.components

import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.size
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.BlendMode
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.ColorFilter
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.androidcompose.R

@Composable
// 定义一个ImageSample函数，用于显示一张图片
fun ImageSample() {
    // 使用Image函数显示一张图片
    Image(
        // 设置图片资源
        painter = painterResource(id = R.drawable.nb),
        // 设置图片的描述
        contentDescription = null,
        // 设置图片的修饰符，这里设置了图片的大小为50dp
        modifier = Modifier.size(50.dp),
        // 设置图片的缩放模式，这里设置为裁剪模式
        contentScale = ContentScale.Crop,
        // 设置图片的滤镜，这里设置了红色滤镜
        colorFilter = ColorFilter.tint(Color.Red, blendMode = BlendMode.Color)
    )
}

@Preview
@Composable
fun ImageSamplePreview() {
    ImageSample()
}