package com.example.androidcompose.components

import android.util.Log
import androidx.compose.foundation.text.ClickableText
import androidx.compose.foundation.text.selection.SelectionContainer
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.SpanStyle
import androidx.compose.ui.text.buildAnnotatedString
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.text.style.TextDecoration
import androidx.compose.ui.text.withStyle
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.sp
import com.example.androidcompose.R


@Composable
fun TextSample() {


//    Text(text = "Hello World")
    SelectionContainer {
        Text(text = stringResource(id = R.string.text),
            color = Color.Green,
            fontSize = 20f.sp,
            letterSpacing = 10.sp,
            textDecoration = TextDecoration.combine(
                listOf(
                    TextDecoration.Underline,
                    TextDecoration.LineThrough
                )
            ),
            textAlign = TextAlign.End,
            style = MaterialTheme.typography.h1
        )
    }
}

@Preview(widthDp = 100)
@Composable
fun TextSamplePreview() {
    TextSample()
}