
## 升级npm和node.js版本
从官网下载LTS版本：https://nodejs.org/en/download/

```
npm install npm@latest -g
```

## 打包

### 安装Electron Forge

```
npm install --save-dev @electron-forge/cli
npx electron-forge import
```

### 构建可分发文件
最好在forge.config.js对代码进行签名
```
npm run make
```