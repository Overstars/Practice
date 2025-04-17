package com.overstars.myapplication.ui.screens

import androidx.compose.foundation.layout.Column
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import com.overstars.myapplication.ui.components.TopAppBar

@Composable
fun StudyScreen(statusBarHeight: Int) {

    Column (modifier = Modifier) {
        TopAppBar (statusBarHeight) {
            Text(text = "学习页面.")
        }
        Text(text = "学习页面内容")
    }
}

@Preview
@Composable
fun StudyScreenPreview() {
    StudyScreen(30)
}