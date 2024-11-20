import React, { useState } from 'react'
import data from './data'

const Accordion = () => {
  const [selected, setSelected] = useState(null)

  const handleSingleClick = (id) => {
    setSelected(selected ? null : id)
  }
//   console.log(setSelected);
  

  return (
    <div>
      <div>
        {data && data.length > 0 ? (
          data.map((item) => (
            <div onClick={() => handleSingleClick(item.id)} key={item.id}>
              <div>
                <h2>{item.question}</h2>
                <span>+</span>
              </div>
              {selected === item.id ? <div>{item.answer}</div>: null}
            </div>
          ))
        ) : (
          <h2>There was no Data Found!!!</h2>
        )}
      </div>
    </div>
  )
}

export default Accordion
