package org.example;

import java.util.Scanner;


public class Main {
    public static Scanner scanner = new Scanner(System.in);
    static class Node{
        int left,right;
        public Node(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }
    public static int inorderCnt = 0;
    public static int cnt = 0;
    public static boolean visited[];
    public static Node tree[];
    public static int n;
    public static int lastNode = 0;
    public static void init() {
        n = scanner.nextInt();
        tree = new Node[n + 1];
        visited = new boolean[n + 1];
        for(int i = 0; i < n; i++) {
            int par,l,r;
            par = scanner.nextInt();
            l = scanner.nextInt();
            r = scanner.nextInt();

            tree[par] = new Node(l,r);
        }
    }

    public static void firstInOrder(int idx) {
        if(tree[idx].left != -1) {
            firstInOrder(tree[idx].left);
        }
        inorderCnt++;
        if(inorderCnt == n) {
            lastNode = idx;
        }
        if(tree[idx].right != -1) {
            firstInOrder(tree[idx].right);
        }
    }
    public static boolean isEnd = false;
    public static int inOrder(int idx) {
        int ans = 0;
        if(tree[idx].left != -1) {
            if(!isEnd) ans++;
            ans += inOrder(tree[idx].left);
            if(!isEnd) ans++;
        }
        if(idx == lastNode) isEnd = true;
        if(tree[idx].right != -1) {
            if(!isEnd) ans++;
            ans += inOrder(tree[idx].right);
            if(!isEnd) ans++;
        }
        return ans;
    }
    public static void solution() {
        init();
        firstInOrder(1);
        System.out.println(inOrder(1));
    }
    public static void main(String[] args) {
        solution();
    }
}
