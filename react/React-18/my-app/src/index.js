import React from 'react'
import ReactDOM from 'react-dom/client'

import './index.css'

const Books = [
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/71xXzFQz7DL._AC_UL900_SR900,600_.jpg',
    title: "You're My Little Christmas Cookie",
    author: 'Nicola Edwards',
    id: 1,
  },
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/81P9B8sY4AL._AC_UL900_SR900,600_.jpg',
    title: 'How To Catch A Turkey',
    author: 'Adam Wallace',
    id: 2,
  },
]

const BookList = () => {
  const someValue = 'shakeAndBake'
  const displayValue = () => {
    console.log(someValue)
  }
  return (
    <section className="booklist">
      {Books.map((book) => {
        return <Book {...book} key={book.id} displayValue={displayValue} />
      })}
    </section>
  )
}

const Book = (props) => {
  const { image, title, author, displayValue } = props

  return (
    <article className="book">
      <img src={image} alt={title} />
      <h2>{title}</h2>
      <button onClick={displayValue}>click me</button>
      <h4>{author}</h4>
    </article>
  )
}

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<BookList />)

// 12 - Booklist ~ Coding Addict
