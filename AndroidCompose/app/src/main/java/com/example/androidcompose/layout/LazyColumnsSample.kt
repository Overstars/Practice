package com.example.androidcompose.layout

import android.util.Log
import androidx.compose.foundation.*
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.rememberLazyListState
import androidx.compose.foundation.lazy.items
import androidx.compose.material.ExperimentalMaterialApi
import androidx.compose.material.Icon
import androidx.compose.material.ListItem
import androidx.compose.material.Text
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountBox
import androidx.compose.runtime.Composable
import androidx.compose.runtime.DisposableEffect
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.launch

@OptIn(ExperimentalMaterialApi::class)
@Composable
fun LazyColumnsSample() {
    val data = listOf(
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20
    )
    val scrollState = rememberScrollState()

    val coroutineScope = rememberCoroutineScope ()

    Column(
        modifier = Modifier.verticalScroll(scrollState)
    ) {
        data.forEach{
            ListItem(
                icon = {
                    Icon(
                        imageVector = Icons.Default.AccountBox,
                        contentDescription = null
                    )
                }, text = {
                    Text(text = "Title $it.")
                }, secondaryText = {
                    Text(text = "Subtitle.")
                }, modifier = Modifier.clickable {
                    coroutineScope.launch {
                        scrollState.animateScrollTo(scrollState.maxValue)
                    }
                }
            )
            DisposableEffect(Unit) {
                Log.d("====", "effect : $it")
                onDispose {
                    Log.d("====", "effect dispose : $it")
                }
            }
        }
    }
}


@OptIn(ExperimentalMaterialApi::class, ExperimentalFoundationApi::class)
@Composable
fun LazyColumnsSample2() {
    val data = listOf(
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20
    )

//    LazyColumn {
//        item {
//            Text(text = "Header")
//        }
//    }

    val lazyListState = rememberLazyListState()
    val coroutineScope = rememberCoroutineScope ()

    LazyColumn(state = lazyListState){
        stickyHeader {
            Text(
                text = "Header",
                modifier = Modifier
                    .background(color = Color.Gray)
                    .fillMaxSize()
                    .padding(8.dp)
            )
        }
        items(data) {
            ListItem(icon = {
                    Icon(
                        imageVector = Icons.Default.AccountBox,
                        contentDescription = null
                    )
                }, text = {
                    Text(text = "Title $it.")
                }, secondaryText = {
                    Text(text = "Subtitle.")
                }, modifier = Modifier.clickable {
                    coroutineScope.launch {
                        lazyListState.animateScrollToItem(data.size - 1)
                    }
                }
            )
            DisposableEffect(Unit) {
                Log.d("====", "effect : $it")
                onDispose {
                    Log.d("====", "effect dispose : $it")
                }
            }
        }
    }
}
@Preview
@Composable
fun LazyColumnsSamplePreview() {
    LazyColumnsSample2()
}