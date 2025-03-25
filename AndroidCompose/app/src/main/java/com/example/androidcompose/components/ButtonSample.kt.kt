package com.example.androidcompose.components

import android.util.Log
import androidx.compose.material.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.graphics.Color

@Composable
fun ButtonSample() {
    Button(
        onClick = {
            Log.d("?????", "点击了按钮")
        },
        colors = ButtonDefaults.buttonColors(backgroundColor = Color.Gray)
    ) {
            Text(text = "不点不是中国人")
    }

//    TextButton(onClick = {  }) {
//        Text(text = "点了就是中国人")
//    }

//    OutlinedButton(onClick = {}) {
//        Text(text = "点了还是中国人")
//    }
}

@Preview
@Composable
fun ButtonSamplePreview() {
    ButtonSample()
}