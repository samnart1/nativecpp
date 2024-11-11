import React from 'react'
import ReactDOM from 'react-dom/client'

import './index.css'

const Books = [
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/71xXzFQz7DL._AC_UL900_SR900,600_.jpg',
    title: "You're My Little Christmas Cookie",
    author: 'Nicola Edwards',
  },
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/71xXzFQz7DL._AC_UL900_SR900,600_.jpg',
    title: "You're My Little Christmas Cookie",
    author: 'Nicola Edwards',
  },
]

const BookList = () => {
  return (
    <section className="booklist">
      {Books}
    </section>
  )
}

const Book = (props) => {
  console.log(props)

  return (
    <article className="book">
      <img src={props.image} alt={props.title} />
      <h2>{props.title}</h2>
      <h4>{props.author}</h4>
    </article>
  )
}

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<BookList />)

// 12 - Booklist ~ Coding Addict
