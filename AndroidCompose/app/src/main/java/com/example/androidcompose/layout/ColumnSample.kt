package com.example.androidcompose.layout

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.size
import androidx.compose.material.Divider
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp

@Composable
fun ColumnSample() {

    Column(
        modifier = Modifier
            .size(160.dp)
            .background(Color.Green)
    ) {
        Text(
            text = "Hello",
            modifier = Modifier
                .weight(1f)
                .background(Color.Yellow)
        )

        Spacer(
            modifier = Modifier.height(16.dp)
        )

        Divider()

        Text(
            text = "World",
            modifier = Modifier
                .weight(2f)
                .background(Color.Red)
        )
    }
}

@Preview
@Composable
fun ColumnSamplePreview() {
    ColumnSample()
}