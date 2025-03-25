package com.example.androidcompose.components

import androidx.compose.material.Icon
import androidx.compose.material.IconButton
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountBox
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.tooling.preview.Preview
import com.example.androidcompose.R

@Composable
fun IconSample() {
    Icon(
        imageVector = Icons.Default.AccountBox,
        contentDescription = "Favorite",
        tint = Color.Red
    )
    IconButton(onClick = {}) {
        Icon(imageVector = Icons.Default.AccountBox, contentDescription = "Favorite")
    }
//    Icon(painter = painterResource(id = R.mipmap.ic_launcher), contentDescription = "Favorite")
}

@Preview
@Composable
fun IconSamplePreview() {
    IconSample()
}