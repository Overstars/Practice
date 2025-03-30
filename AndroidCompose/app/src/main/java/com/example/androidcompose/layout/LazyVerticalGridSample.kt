package com.example.androidcompose.layout

import androidx.compose.foundation.lazy.grid.GridCells
import androidx.compose.foundation.lazy.grid.LazyVerticalGrid
import androidx.compose.foundation.lazy.items
import androidx.compose.material.Card
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.tooling.preview.Preview
import java.lang.reflect.Modifier

@Composable
fun LazyVerticalGridSample() {
    val data = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20)

//    LazyVerticalGrid(
////        cells = GridCells.Fixed(3) {
////            items(data) {
////                Card() {
////                    Text("Grid Item $it", modifier = Modifier.padding(16.dp)
////                }
////            }
////        }
//    )
}

@Preview
@Composable
fun LazyVerticalGridSamplePreview() {
    LazyVerticalGridSample()
}